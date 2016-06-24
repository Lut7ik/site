<?php
/**
 * Build delete form page.
 */
function my_database_delete_form($form, $form_state) {
  $form = array();
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('delete'),
  );
  $form['cancel'] = array(
    '#markup' => l(t('Cancel'), 'my_database'),
  );
  return $form;
}
___________________________________________________________________________________________________________________________________________________________________________