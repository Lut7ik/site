<?php
/**
 * Build form for insert data.
 */
function my_database_insert_form($form, $form_state) {
  $form = array();
  $form['number'] = array(
    '#title' => t('Number'),
    '#type' => 'textfield',
    '#maxlength' => 10,
    '#description' => t('Only numbers'),
    '#required' => TRUE,
  );
  $form['teaser'] = array(
    '#title' => t('Teaser'),
    '#type' => 'textfield',
    '#maxlength' => 150,
    '#required' => TRUE,
  );
  $form['text'] = array(
    '#title' => t('Text'),
    '#type' => 'textarea',
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}
___________________________________________________________________________________________________________________________________________________________________________