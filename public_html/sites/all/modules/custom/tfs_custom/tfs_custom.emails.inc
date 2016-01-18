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
  global $base_url;
//  $query = db_select('users', 'u')
//    ->fields('u', array('mail', 'uid'))
//    ->condition('u.uid', 1, '!=')
//    ->condition('u.uid', 43, '!=')
//    ->orderBy('u.created','DESC')
//    ->condition('rca.field_rebecca_confirm_attendance_value','','IS NULL')
//    ->range(0,100);
//  $query->leftJoin('field_data_field_rebecca_confirm_attendance', 'rca', 'rca.entity_id = u.uid');
//  $result = $query->execute();

//  $query = db_select('users', 'u')
//    ->fields('u', array('mail', 'uid'))
//    ->condition('u.uid', array(1))
//    ->orderBy('u.created',' DESC')
////    ->condition('rca.field_rebecca_confirm_attendance_value','','IS NULL')
//    ->range(0,100);
//  $query->leftJoin('field_data_field_rebecca_confirm_attendance', 'rca', 'rca.entity_id = u.uid');
//  $result = $query->execute();

  foreach ($result as $row) {
    $params = array(
      'mail' => $row->mail,
      'CUSTOM_CONFIRM_LINK' => l(t('HERE'), $base_url . "/rebecca/new/confirm-attendance/$row->uid"),
    );
    drupal_mail('tfs_custom', 'send_rebecca_confirmation_email', $row->mail, language_default(), $params);
    watchdog('tfs_custom_mail', t('Confirmation email has been sent to !mail - confirm uid is !uid',
      array(
        '!uid' => $row->uid,
        '!mail' => $row->mail,
      )));
  }
}