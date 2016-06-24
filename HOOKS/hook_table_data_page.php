<?php
/**
 * Build page with table.
 */
function my_database_table_data_page() {
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
___________________________________________________________________________________________________________________________________________________________________________