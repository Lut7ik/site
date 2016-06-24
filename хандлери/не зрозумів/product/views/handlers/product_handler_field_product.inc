<?php
 
/**
 * @file
 * Contains the product id field handler.
 */
 
/**
 * Field handler to provide simple renderer that allows linking to a product.
 */
class product_handler_field_product extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
 
    // Если выбрана опция "Выводить в виде ссылки", до достаем id продукта.
    if (!empty($this->options['link_to_product'])) {
      $this->additional_fields['id'] = array('table' => 'product', 'field' => 'id');
    }
  }
 
  /**
   * Обьявляем настройки для поля.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_product'] = array('default' => 'none');
    return $options;
  }
 
  /**
   * Описываем форму с натсройками.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
 
    $form['link_to_product'] = array(
      '#title' => t('Link this field to the original piece of product'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_product']),
    );
 
    parent::options_form($form, $form_state);
  }
 
  /**
   * Выводим поле в виде ссылки на продукт.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_product']) && !empty($this->additional_fields['id'])) {
      $id = $this->get_value($values, 'id');
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'product/' . $id;
    }
 
    return $data;
  }
 
  /**
   * Выводим поле.
   */
  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}