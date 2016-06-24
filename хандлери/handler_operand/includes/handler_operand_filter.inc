<?php
/**
 * @file
 * Custom views handler definition.
 */

/**
 * Custom handler class.
 * @ingroup views_field_handlers
 */
class handler_operand_filter extends views_handler_filter_numeric {
  /**
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
    $this->ensure_my_table();
    $field = "ROUND(testnode.int_count*testnode.int_total)";

    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($field);
    }
  }

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

}
