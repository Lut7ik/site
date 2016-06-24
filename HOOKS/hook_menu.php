<?php
/**
 * Implements hook_menu().
 */
function my_database_menu() {
  $items['my_database/insert'] = array(
    'title' => 'Page for insert data',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('my_database_insert_form'),
    'access arguments' => array('administer site configuration'),
	'menu_name'				=> 'main-menu',
  );
  $items['my_database'] = array(
    'title' => 'Table with data',
    'page callback' => 'my_database_table_data_page',
    'access arguments' => array('administer site configuration'),
	'menu_name'				=> 'main-menu',
  );
  $items['my_database/%/delete'] = array(
   	'title callback' => 'my_database_delete_page_title',
    'title arguments' => array(1),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('my_database_delete_form', 1),
    'access arguments' => array('administer site configuration'),
	'menu_name'				=> 'main-menu',
  );
  return $items;
}
___________________________________________________________________________________________________________________________________________________________________________