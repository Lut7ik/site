<?php
/**
 * Submit for my_database_insert_form.
 */
function my_database_insert_form_submit($form, &$form_state) {
  $query = db_insert('my_table')
    ->fields(array(
      'number' => $form_state['values']['number'],
      'teaser' => $form_state['values']['teaser'],
      'text'   => $form_state['values']['text'],
    ))
    ->execute();
  if ($query > 0) {
    drupal_set_message(t('Data has been successfully sent.'));
  }
  else {
    drupal_set_message(t("Data hasn't been sent."), 'error');
  }
}
/** 
 * Submit function for calculator_page_form. 
 */
function calculator_page_form_submit($form, &$form_state) {
  $num1 = $form_state['values']['number1'];
  $num2 = $form_state['values']['number2'];
 switch ($form_state['values']['operator']) {
      case 0:
           $result = $num1 + $num2;
      break;

      default:
            $result = $num1 - $num2;
      break;
  }
  drupal_set_message(t('Result is @num', array('@num' => $result)));
}__________________________________________________________________________________________________________________________________________________________________________
/**
*функция сабмита: В функции мы должны обработать наш оператор и, в зависимости от результата выбора оператора, вывести соответствующее сообщение на экран.
*                 Здесь мы видим, что сначала идет переприсвоение результатов в отдельные переменные. Далее, относительно ключа значения массива оператора 
*                (но не самого значения!), производим сложение или вычитание чисел. Затем выводим сообщение с использованием функции “drupal_set_message”.
*/