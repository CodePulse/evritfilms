<?php

function tfs_custom_basketmouth_bulk_send($uid, $email, $params, &$context) {

  $send_email = drupal_mail('tfs_custom', 'reminder_basket_mouth', $email, language_default(), $params);

  if ($send_email['result']) {
    $context['results']['success'][] = $email . ' - ' . $uid;
  }
  else {
    $context['results']['error'][] = $email . ' - ' . $uid;
  }
  $context['message'] = t('Now sending Email to %email.', array('%email' => $uid . $email));
  $context['finished'] = 1;

}

function tfs_custom_basketmouth_bulk_send_finish ($success, $results, $operations) {
  if ($success) {
    if (count($results['errors']) > 0) {
      drupal_set_message(t('!sent sent with !errors.', array(
        '!sent' => format_plural(count($results['success']), '1 email', '@count emails'),
        '!errors' => format_plural(count($results['errors']), '1 error', '@count errors'),
      )), 'error');
    }
    else {
      drupal_set_message(t('!email sent.', array(
        '!email' => format_plural(count($results['success']), '1 email', '@count emails'),
      )), 'status');
    }
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }

}