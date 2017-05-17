<?php
/**
 * @file
 * codepulse_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function codepulse_content_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event|node|event|form';
  $field_group->group_name = 'group_event';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_age_rating',
      2 => 'field_director',
      3 => 'field_poster',
      4 => 'field_release_date',
      5 => 'field_trailer',
      6 => 'field_writers',
      7 => 'title',
      8 => 'path',
      9 => 'field_teaser_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Event');

  return $field_groups;
}
