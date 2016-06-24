<?php
/**
 * @file
 * Custom views handler definition.
 */

/**
 * Custom handler class.
 * @ingroup views_field_handlers
 */
class handler_operand_field extends views_handler_field_numeric {
  /**
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */


  /**
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    if (isset($values->testnode_int_count) && isset($values->testnode_int_total)) {
      return round($values->testnode_int_count*$values->testnode_int_total);
    } else {
      return 0;
    }
  }
    function query() {

  }
}
