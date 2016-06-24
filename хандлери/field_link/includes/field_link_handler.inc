<?php
/**
 * @file
 * Custom views handler definition.
 */

/**
 * Custom handler class.
 * @ingroup views_field_handlers
 */
class field_link_handler extends views_handler_field {
  /**
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {

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
  function render($fields) {
    return l(t('View author'), url('user/' . $fields->node_uid));
  }
}
