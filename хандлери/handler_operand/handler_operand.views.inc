<?php
/**
 * Implements hook_views_data_alter().
 */
function handler_operand_views_data_alter(&$data) {
	$data['testnode']['table']['group'] = t('testnode_group');

$data['testnode']['table']['base'] = array(
     'field' => 'tid',
     'title' => t('testnode_base'),
     'help' => t("testnode help"),
  );

$data['testnode']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field'	=> 'tid',
  );
  
$data['testnode']['tid'] = array(
      'title' => t('Test Node ID'),
      'help'   => 'Help Node ID',
	  'field' => array('handler' => 'views_handler_field',),
      'filter' => array('handler' => 'views_handler_filter_numeric',),
    );

$data['testnode']['nid'] = array(
      'title' => t('Test Node NID'),
      'help'   => 'Help Node NID',
	  'field' => array('handler' => 'views_handler_field',),
      'filter' => array('handler' => 'views_handler_filter_numeric',),
    );	

$data['testnode']['int_count'] = array(
      'title' => t('Test Node int_count'),
      'help'   => 'Help Node int_count',
	  'field' => array('handler' => 'views_handler_field',),
      'sort'   => array('handler' => 'views_handler_sort'),
	  'filter' => array('handler' => 'views_handler_filter_numeric',),
    );	

$data['testnode']['int_total'] = array(
      'title' => t('Test Node int_total'),
      'help'   => 'Help Node int_total',
	  'field' => array('handler' => 'views_handler_field',),
      'sort'   => array('handler' => 'views_handler_sort'),
	  'filter' => array('handler' => 'views_handler_filter_numeric',),
    );
	
$data['testnode']['percentage'] = array(
      'title' => t('Virtual Node percentage'),
      'help'   => 'Help Virtual Node percentage',
	  'field' => array('handler' => 'handler_operand_field',),
      'sort'   => array('handler' => 'views_handler_sort_formula','formula' => 'ROUND(testnode.int_count*testnode.int_total)',),
	  'filter' => array('handler' => 'handler_operand_filter',),
    ); 	
}

