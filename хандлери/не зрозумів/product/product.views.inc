<?php
/**
 * Implements hook_views_data().
 */
function product_views_data() {
  $data = array();
 
  // Значение ключа 'group' будет использовано в UI для группировки полей,
  // фильтров, сортировки и т.д.
  $data['product']['table']['group']  = t('Product');
 
  // Описываем базовую таблицу, из которой Views будет доставать данные.
  $data['product']['table']['base'] = array(
    'field' => 'id', // Поле идентификатора.
    'title' => t('Product'),
  );
 
  // Указываем, что таблица хранит данные об сущности.
  $data['product']['table']['entity type'] = 'product';
 
  // Описываем поле "id".
  $data['product']['id'] = array(
    'title' => t('Product ID'), // Человеко-понятное название поля, которое отображается в UI.
    'help' => t('The unique internal identifier of the product.'), // Описание поля, которое отображается в UI.
    // Информация для вывода id.
    'field' => array(
      'handler' => 'product_handler_field_product', // Обработчик, который будет выводить значение поля.
      'click sortable' => TRUE, // Используются для сортировки при отображении данных в таблице.
    ),
    // Информация для принятия id в качестве аргумента.
    'argument' => array(
      'handler' => 'product_handler_argument_product_id', // Обработчик, который будет принимать аргумент, и фильтровать данные по нему.
      'name field' => 'id', // Поле для отображения summary.
      'numeric' => TRUE,
      'validate type' => 'id',
    ),
    // Информация для принятия id в качестве фильтра.
    'filter' => array(
      'handler' => 'views_handler_filter_numeric', // Обработчик, который будет фильтровать данные.
    ),
    // Информация для сортировки по id.
    'sort' => array(
      'handler' => 'views_handler_sort', // Обработчик, который будет сортировать данные.
    ),
  );
 
  // Описываем поле "заголовок".
  $data['product']['title'] = array(
    'title' => t('Title'),
    'help' => t('The product title.'),
    // Информация для вывода заголовка.
    'field' => array(
      'field' => 'title',
      'group' => t('Product'),
      'handler' => 'product_handler_field_product',
      'click sortable' => TRUE,
      'link_to_product_default' => TRUE,
    ),
    // Информация для принятия заголовка в качестве аргумента.
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    // Информация для принятия заголовка в качестве фильтра.
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // Информация для сортировки по заголовку.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
 
  // Описываем поле "Дата создания".
  $data['product']['created'] = array(
    'title' => t('Post date'),
    'help' => t('The date the product was created.'),
    // Информация для вывода даты создания.
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    // Информация для принятия даты создания в качестве фильтра.
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    // Информация для сортировки по дате создания.
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
 
  // Описываем поле "Дата обновления".
  $data['product']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the product was last updated.'),
    // Информация для вывода даты обновления.
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    // Информация для принятия даты обновления в качестве фильтра.
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    // Информация для сортировки по дате обновления.
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
 
  // Описываем поле "Статус".
  $data['product']['status'] = array(
    'title' => t('Product status'),
    'help' => t('The workflow status of the product.'),
    // Информация для вывода статуса.
    'field' => array(
      'handler' => 'product_handler_field_product_status',
      'click sortable' => TRUE,
    ),
    // Информация для принятия статуса в качестве фильтра.
    'filter' => array(
      'handler' => 'product_handler_filter_product_status',
    ),
    // Информация для сортировки по статусу.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
 
  // Описываем поле "uid".
  $data['product']['uid'] = array(
    'title' => t('User uid'),
    'help' => t('The user author. If you need more fields than the uid add the content: author relationship'),
    // Информация для связи таблицы "product" с таблицей "users".
    'relationship' => array(
      'title' => t('Author'), // Человеко-понятное название связи, которое отображается в UI.
      'help' => t('Relate product to the user who created it.'), // Описание связи, которое отображается в UI.
      'handler' => 'views_handler_relationship',
      'base' => 'users', // Название таблицы, которая будет присоединена, в данном прмиере это таблица "users".
      'field' => 'uid', // По какому полю таблицы будут связаны.
      'label' => t('author'), // Ключевое слово связи, которое используется в UI.
    ),
    // Информация для вывода uid.
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
    // Информация для принятия uid в качестве аргумента.
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    // Информация для принятия uid в качестве фильтра.
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
  );
 
  // Описываем поле с допустимыми операциями над продуктом.
  $data['product']['operations'] = array(
    // Информация для операций.
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the product.'),
      'handler' => 'product_handler_field_product_operations',
    ),
  );
 
  return $data;
}