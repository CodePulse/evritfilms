<div class="latest-event">
  <div class="latest-event__image"><?php print drupal_render($content['field_teaser_image']); ?></div>
  <h4 class="latest-event__title"><?php print $node->title; ?></h4>
  <div class="latest-event__description"><?php print render($body[0]['summary']); ?></div>
  <div class="latest-event__read-more"><?php print l(t('Read more'), 'node/' .$node->nid);?> </div>
</div>