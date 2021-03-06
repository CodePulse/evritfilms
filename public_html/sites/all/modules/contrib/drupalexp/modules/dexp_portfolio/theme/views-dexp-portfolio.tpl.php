<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
//print_r($options);
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php if($options['dexp_portfolio_filter']):?>
  <?php if(isset($categories)):?>
  <div class="portfolio-filters">
		<ul class="dexp-portfolio-filter clearfix" data-option-key="filter">
			<li><a class="btn btn-default active" href="#" data-filter="*"><?php print t('Show All')?></a></li>
			<?php foreach($categories as $key => $c): ?>
				<li>
					<a class="btn btn-default" href="#" data-filter="<?php echo $key; ?>"><?php echo $c; ?></a>
				</li>
			<?php endforeach; ?>
		</ul>
	</div>
  <?php endif;?>
<?php endif;?>  
<div id="<?php print $view_id;?>" class="dexp-grid-items row">
  <?php foreach($rows as $row):?>
    <?php print $row; ?>
  <?php endforeach;?>
</div>