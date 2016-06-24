<?php

/**
 * @file
 * Plugin to handle the panelsless map toolbar'.
 */

$plugin = array(
  'title' => t('panelsless map toolbar'),
  'single' => TRUE,
  'description' => t('panelsless map toolbar.'),
  'category' => t('panelsless'),
  'render last' => TRUE,
);

/**
 * Output function for the panelsless map toolbar'.
 */
function panelsless_map_map_toolbar_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  
  // Logo
  $logo_path = theme_get_setting('logo');
	$variables = array(
		'path' => $logo_path, 
		'alt' => variable_get('site_name'),
		'title' => variable_get('site_name'),
		'attributes' => array('class' => 'logo'),
	);
	$logo_image = theme('image', $variables);
	$logo = l($logo_image, '<front>', array('html' => TRUE));

  $block->content = theme('panelsless_map', array(
    'logo' => $logo,
  ));

  return $block;
}

