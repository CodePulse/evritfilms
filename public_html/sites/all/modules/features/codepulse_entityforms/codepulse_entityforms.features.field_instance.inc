<?php
/**
 * @file
 * codepulse_entityforms.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function codepulse_entityforms_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-contact_us-field_e_mail'
  $field_instances['entityform-contact_us-field_e_mail'] = array(
    'bundle' => 'contact_us',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => NULL,
        'settings' => array(),
        'type' => NULL,
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_e_mail',
    'label' => 'E-mail',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => NULL,
      'settings' => array(
        'size' => 60,
      ),
      'type' => NULL,
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-contact_us-field_message'
  $field_instances['entityform-contact_us-field_message'] = array(
    'bundle' => 'contact_us',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_message',
    'label' => 'Message',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-contact_us-field_name'
  $field_instances['entityform-contact_us-field_name'] = array(
    'bundle' => 'contact_us',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_name',
    'label' => 'Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('E-mail');
  t('Message');
  t('Name');

  return $field_instances;
}
