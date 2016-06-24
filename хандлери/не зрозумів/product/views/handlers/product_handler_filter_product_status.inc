<?php
 
/**
 * @file
 * Provide a product status filter handler.
 */
 
/**
 * Filter by product status.
 */
class product_handler_filter_product_status extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Status');
      $this->value_options = array();
      foreach (product_status_get_title() as $key => $title) {
        $this->value_options[$key] = $title;
      }
    }
  }
}