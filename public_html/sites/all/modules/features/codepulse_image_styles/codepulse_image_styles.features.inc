<?php
/**
 * @file
 * codepulse_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function codepulse_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 265x190.
  $styles['265x190'] = array(
    'label' => '265x190',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 190,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_large_image.
  $styles['blog_large_image'] = array(
    'label' => 'Blog Large Image',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 870,
          'height' => 353,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_timeline.
  $styles['blog_timeline'] = array(
    'label' => 'Blog Timeline',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 502,
          'height' => 265,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_events.
  $styles['homepage_events'] = array(
    'label' => 'Homepage Events',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 350,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_blog.
  $styles['medium_blog'] = array(
    'label' => 'Medium Blog',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 219,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: portfolio.
  $styles['portfolio'] = array(
    'label' => 'portfolio',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
