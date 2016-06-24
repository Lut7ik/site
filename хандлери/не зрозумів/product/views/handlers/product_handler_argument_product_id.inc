<?php
 
/**
 * @file
 * Provide a product id argument handler.
 */
 
/**
 * Argument handler to accept a product id.
 */
class product_handler_argument_product_id extends views_handler_argument_numeric {
  /**
   * Override the behavior of title().
   */
  function title_query() {
    $titles = array();
 
    $result = db_query("SELECT p.title FROM {product} p WHERE p.id IN (:ids)", array(':ids' => $this->value));
    foreach ($result as $product) {
      $titles[] = check_plain($product->title);
    }
 
    return $titles;
  }
}