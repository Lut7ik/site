<?php
 
/**
 * @file
 * Contains the product's operations field handler.
 */
 
/**
 * Field handler to present a product's operations links.
 */
class product_handler_field_product_operations extends views_handler_field {
  function construct() {
    parent::construct();
 
    $this->additional_fields['id'] = 'id';
  }
 
  function option_definition() {
    $options = parent::option_definition();
    $options['add_destination'] = TRUE;
    return $options;
  }
 
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
 
    $form['add_destination'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add a destination parameter to edit and delete operation links so users return to this View on form submission.'),
      '#default_value' => $this->options['add_destination'],
    );
  }
 
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
 
  function render($values) {
    $id = $this->get_value($values, 'id');
 
    $links = array();
 
    $links['edit'] = array(
      'title' => t('Edit'),
      'href' => 'product/' . $id . '/edit',
      'html' => FALSE,
    );
 
    $links['delete'] = array(
      'title' => t('Delete'),
      'href' => 'product/' . $id . '/delete',
      'html' => FALSE,
    );
 
    if ($this->options['add_destination']) {
      $links['edit']['query'] = drupal_get_destination();
      $links['delete']['query'] = drupal_get_destination();
    }
 
    return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
  }
}