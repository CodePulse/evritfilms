<?php

function tfs_custom_confirm_attendance($form, &$form_state, $user){
  $first_name = $user->field_first_name[LANGUAGE_NONE][0]['safe_value'];
  dpm($user);
  $confirmed = $user->field_rebecca_confirm_attendance;

  if (empty($confirmed)) {
    $form['confirm_attendance_intro'] = array(
      '#type' => 'markup',
      '#markup' => t('Welcome <strong>!fname</strong>, will you be attending this event ?', array(
        '!fname' => $first_name,
      )),
    );

    $form['confirm_attendance'] = array(
      '#type' => 'radios',
      '#required' => TRUE,
      '#options' => drupal_map_assoc(array(
        t('Yes'),
        t('No'),
      )),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }
  else {
    drupal_set_message(t('You have already submitted your confirmation. Thank you.'));
  }


  return $form;
}

function tfs_custom_confirm_attendance_submit($form, &$form_state){
  $answer = $form_state['values']['confirm_attendance'];
  $uid = $form_state['build_info']['args'][0]->uid;

  $user_account = user_load($uid);
  $first_name = $user_account->field_first_name[LANGUAGE_NONE][0]['safe_value'];


  $user_account->field_rebecca_confirm_attendance['und'][0]['value'] = $answer;

  user_save($user_account);

  drupal_set_message(t('<strong>!fname</strong>, thank you for your confirmation.',
    array(
      '!fname' => $first_name,
    )));

  drupal_goto('<front>');
}