<?php
 
/**
 * @file
 * Contains the product status field handler.
 */
 
/**
 * Field handler a product status into its readable form.
 */
class product_handler_field_product_status extends product_handler_field_product {
  function render($values) {
    $id = $this->get_value($values);
    $value = product_status_get_title($id);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}