<?php
/**
 * Callback title for delete page.
 */
function my_database_delete_page_title($id) {
  $placeholders = array(':id' => $id);
  $number = db_query("SELECT `number` FROM {my_table} WHERE `id` = :id", $placeholders)->fetchField();
  return t('Are you sure you want to delete item with number "@num"?', array('@num' => $number));
}
___________________________________________________________________________________________________________________________________________________________________________