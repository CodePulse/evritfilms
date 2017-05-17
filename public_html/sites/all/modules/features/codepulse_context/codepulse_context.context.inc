<?php
/**
 * @file
 * codepulse_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function codepulse_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hompeage';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-latest_events-block' => array(
          'module' => 'views',
          'delta' => 'latest_events-block',
          'region' => 'user5',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['hompeage'] = $context;

  return $export;
}
