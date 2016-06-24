<?php
/**
 * Validate for my_database_insert_form.
 */
function my_database_insert_form_validate($form, &$form_state) {
  if (drupal_strlen($form_state['values']['number']) > 10) {  
    form_set_error('number', t('Field "@fieldname" must be less than @c chars.',
      array('@fieldname' => t('Number'), '@c' => 10)));
  }
  elseif (!ctype_digit($form_state['values']['number'])) {
    form_set_error('number', t('Field "number" must contains an integer.'));
  }
  if (drupal_strlen($form_state['values']['teaser']) > 150) {
    form_set_error('teaser', t('Field "@fieldname" must be less than @c chars.',
      array('@fieldname' => t('Teaser'), '@c' => 150)));
  }
}
/** 
 * Validate function for calculator_page_form. 
 */
function calculator_page_form_validate($form, &$form_state) {
 if (!is_numeric($form_state['values']['number1'])) {
    form_set_error('number1', t('Value in field "Number 1" is wrong.'));
  }
 if (!is_numeric($form_state['values']['number2'])) {
    form_set_error('number2', t('Value in field "Number 2" is wrong.'));
  }
}_________________________________________________________________________________________________________________________________________________________________________
/**
*переменнaя &$form_state: Отметим, что данная переменная содержит массив. Значения отправленных данных следует искать в ключе “values”. 
*                         Например, если на валидации нам нужно взять число, которое было введено в поле “number”, 
*                         тогда его следует искать здесь: “$form_state[‘values’][‘number1’]”.
*/
//функция drupal_strlen: возвращает количество символов в строке values имеющей кодировк$ UTF-8.
//функция is_numeric: возвращает TRUE, если values является числом или числовой строкой, FALSE - в ином сл$чае.
/**
*функция $form_set_error: первый аргумент функции 'number' указывает, какой элемент следует подсветить красным в случаи ошибки. 
*                          второй аргумент t('Value in field "number" is wrong.') выводит сообщение об ошибке.
*/
