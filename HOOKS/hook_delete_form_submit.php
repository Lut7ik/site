<?php
/**
 * Submit function for delete form.
 */
function my_database_delete_form_submit($form, &$form_state) {
  $id = $form_state['build_info']['args'][0];
  $result = db_delete('my_table')
    ->condition('id', $id)
    ->execute();
  $placeholders = array('@id' => $id);
  if ($result) {
    drupal_set_message(t('Record @id successfully removed.', $placeholders));
  }
  else {
    drupal_set_message(t('Record @id is undefined.', $placeholders), 'warning');
  }
  $form_state['redirect'] = 'my_database';
}
___________________________________________________________________________________________________________________________________________________________________________
/**
  * function my_database_table_data_page() {
  $header = array(t('ID'), t('Number'), t('Teaser'), t('Text'), t('Actions'));
  $rows = array();
  $query = db_select('my_table', 't')
    ->fields('t', array('id', 'number', 'teaser', 'text'))
    ->execute();
  while ($value = $query->fetchAssoc()) {
    $rows[] = array(
      $value['id'],
      $value['number'],
      $value['teaser'],
      $value['text'],
      l(t('Delete'), "my_database/{$value['id']}/delete"),
    );
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}
 * function my_database_delete_page_title($id) {
  $placeholders = array(':id' => $id);
  $number = db_query("SELECT `number` FROM {my_table} WHERE `id` = :id", $placeholders)->fetchField();
  return t('Are you sure you want to delete item with number "@num"?', array('@num' => $number));
}
 * function my_database_delete_form($form, $form_state) {
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
 */