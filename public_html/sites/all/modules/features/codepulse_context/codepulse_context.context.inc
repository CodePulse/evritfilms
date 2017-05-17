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
        'views-homepage_events_blocks-block' => array(
          'module' => 'views',
          'delta' => 'homepage_events_blocks-block',
          'region' => 'user3',
          'weight' => '-10',
        ),
        'views-homepage_events_blocks-block_1' => array(
          'module' => 'views',
          'delta' => 'homepage_events_blocks-block_1',
          'region' => 'user4',
          'weight' => '-10',
        ),
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
