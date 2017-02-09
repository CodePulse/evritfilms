<?php
/**
 * Page callback for list of emails sent by the system.
 * @param $form
 * @param $form_state
 * @return mixed
 */
function tfs_custom_email_form($form, &$form_state){
  /**
   * Send for confirmation
   */
  $form['tfs_custom_ask_confirm'] = array(
    '#type' => 'fieldset',
    '#title' => t('First confirmation email sent to users'),
    '#description' => t('This email will be sent to users asking them to confirm attendance'),
    '#required' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $confirm_subject = variable_get('tfs_custom_ask_confirm_subject');
  $form['tfs_custom_ask_confirm']['tfs_custom_ask_confirm_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Confirmation email - Subject'),
    '#required' => TRUE,
    '#default_value' => $confirm_subject,
  );

  $confirm_body = variable_get('tfs_custom_ask_confirm_body',array('value' => '', 'format' => ''));
  $form['tfs_custom_ask_confirm']['tfs_custom_ask_confirm_body'] = array(
    '#title' => t('Confirmation email - Message'),
    '#required' => TRUE,
    '#type' => 'text_format',
    '#default_value' => check_markup($confirm_body['value'], $confirm_body['format']),
    '#format' => !empty($confirm_body['format']) ? $confirm_body['format'] : 'full_html',
  );

  $form['send_emails'] = array(
    '#type' => 'submit',
    '#value' => t('Send emails'),
    '#submit' => array('tfs_custom_send_emails'),
  );


  return system_settings_form($form);
}

/**
 * @param $form
 * @param $form_state
 */
function tfs_custom_send_emails($form, &$form_state){

  $batch = array(
    'operations' => array(),
    'finished' => 'tfs_custom_basketmouth_bulk_send_finish',
    'title' => t('Processing emails'),
    'init_message' => t('Starting sending emails...'),
    'error_message' => t('Sending email has encountered an error.'),
    'progress_message' => t('Processed @current out of @total (@remaining remaining). @estimate until finish.'),
    'file' => drupal_get_path('module', 'tfs_custom') . '/tfs_custom.batch.inc',
  );

  $query = db_select('users', 'u')
    ->fields('u', array('uid', 'mail'))
    ->condition('u.uid', array(0, 43, 548, 550),'NOT IN');
  $results = $query->execute();

  foreach ($results as $result) {
    $user = user_load($result->uid);
    $first_name = field_get_items('user', $user, 'field_first_name');

    $params = array(
      'first_name' => $first_name[0]['value'],
    );

    $batch['operations'][] = array(
      'tfs_custom_basketmouth_bulk_send',
      array($result->uid, $result->mail, $params),
    );

  }

  batch_set($batch);

}