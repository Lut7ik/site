<?php
/**
 * Implements hook_views_default_views().
 */
function KATEGORII_views_default_views() {
$view = new view();
$view->name = 'nov';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'товари таксономії';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Всі товари';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['use_more_text'] = 'ще';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
$handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
$handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
$handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
$handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
$handler->display->display_options['style_plugin'] = 'table';
/* Зв'язок: Вміст: Товари за посиланнями */
$handler->display->display_options['relationships']['field_sviy_tovar_product_id']['id'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['relationships']['field_sviy_tovar_product_id']['table'] = 'field_data_field_sviy_tovar';
$handler->display->display_options['relationships']['field_sviy_tovar_product_id']['field'] = 'field_sviy_tovar_product_id';
/* Зв'язок: Вміст: Бренд (field_brend) - реверс */
$handler->display->display_options['relationships']['reverse_field_brend_commerce_product']['id'] = 'reverse_field_brend_commerce_product';
$handler->display->display_options['relationships']['reverse_field_brend_commerce_product']['table'] = 'node';
$handler->display->display_options['relationships']['reverse_field_brend_commerce_product']['field'] = 'reverse_field_brend_commerce_product';
/* Поле: Торгівля: Товар: Артикул */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['fields']['sku']['link_to_product'] = 0;
/* Поле: Вміст: Заголовок */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Поле: Торгівля: Товар: Короткий опис */
$handler->display->display_options['fields']['field_koropis']['id'] = 'field_koropis';
$handler->display->display_options['fields']['field_koropis']['table'] = 'field_data_field_koropis';
$handler->display->display_options['fields']['field_koropis']['field'] = 'field_koropis';
$handler->display->display_options['fields']['field_koropis']['relationship'] = 'field_sviy_tovar_product_id';
/* Поле: Торгівля: Товар: Прихідна ціна */
$handler->display->display_options['fields']['field_cinapruhidna']['id'] = 'field_cinapruhidna';
$handler->display->display_options['fields']['field_cinapruhidna']['table'] = 'field_data_field_cinapruhidna';
$handler->display->display_options['fields']['field_cinapruhidna']['field'] = 'field_cinapruhidna';
$handler->display->display_options['fields']['field_cinapruhidna']['relationship'] = 'field_sviy_tovar_product_id';
/* Поле: Торгівля: Товар: Ціна для гуртових покупців */
$handler->display->display_options['fields']['field_cinagurtom']['id'] = 'field_cinagurtom';
$handler->display->display_options['fields']['field_cinagurtom']['table'] = 'field_data_field_cinagurtom';
$handler->display->display_options['fields']['field_cinagurtom']['field'] = 'field_cinagurtom';
$handler->display->display_options['fields']['field_cinagurtom']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['fields']['field_cinagurtom']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['field_cinagurtom']['settings'] = array(
  'calculation' => FALSE,
);
/* Поле: Торгівля: Товар: Ціна для роздрібних покупців */
$handler->display->display_options['fields']['field_cinaklientov']['id'] = 'field_cinaklientov';
$handler->display->display_options['fields']['field_cinaklientov']['table'] = 'field_data_field_cinaklientov';
$handler->display->display_options['fields']['field_cinaklientov']['field'] = 'field_cinaklientov';
$handler->display->display_options['fields']['field_cinaklientov']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['fields']['field_cinaklientov']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['field_cinaklientov']['settings'] = array(
  'calculation' => FALSE,
);
/* Поле: Торгівля: Товар: Час доставки */
$handler->display->display_options['fields']['field_chas']['id'] = 'field_chas';
$handler->display->display_options['fields']['field_chas']['table'] = 'field_data_field_chas';
$handler->display->display_options['fields']['field_chas']['field'] = 'field_chas';
$handler->display->display_options['fields']['field_chas']['relationship'] = 'field_sviy_tovar_product_id';
/* Поле: Торгівля: Товар: Дата оновлення */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'commerce_product';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['fields']['changed']['date_format'] = 'long';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
/* Поле: Торгівля: Товар: Зображення товару */
$handler->display->display_options['fields']['field_zobrtovaru']['id'] = 'field_zobrtovaru';
$handler->display->display_options['fields']['field_zobrtovaru']['table'] = 'field_data_field_zobrtovaru';
$handler->display->display_options['fields']['field_zobrtovaru']['field'] = 'field_zobrtovaru';
$handler->display->display_options['fields']['field_zobrtovaru']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['fields']['field_zobrtovaru']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_zobrtovaru']['settings'] = array(
  'image_style' => 'thumbnail',
  'image_link' => 'content',
);
/* Поле: Торгівля: Товар: Бренд */
$handler->display->display_options['fields']['field_brend']['id'] = 'field_brend';
$handler->display->display_options['fields']['field_brend']['table'] = 'field_data_field_brend';
$handler->display->display_options['fields']['field_brend']['field'] = 'field_brend';
$handler->display->display_options['fields']['field_brend']['relationship'] = 'field_sviy_tovar_product_id';
/* Поле: Вміст: Опис бренду */
$handler->display->display_options['fields']['field_opisbrendu']['id'] = 'field_opisbrendu';
$handler->display->display_options['fields']['field_opisbrendu']['table'] = 'field_data_field_opisbrendu';
$handler->display->display_options['fields']['field_opisbrendu']['field'] = 'field_opisbrendu';
$handler->display->display_options['fields']['field_opisbrendu']['exclude'] = TRUE;
/* Критерій сортування: Торгівля: Товар: Прихідна ціна (field_cinapruhidna:amount) */
$handler->display->display_options['sorts']['field_cinapruhidna_amount']['id'] = 'field_cinapruhidna_amount';
$handler->display->display_options['sorts']['field_cinapruhidna_amount']['table'] = 'field_data_field_cinapruhidna';
$handler->display->display_options['sorts']['field_cinapruhidna_amount']['field'] = 'field_cinapruhidna_amount';
$handler->display->display_options['sorts']['field_cinapruhidna_amount']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['sorts']['field_cinapruhidna_amount']['exposed'] = TRUE;
$handler->display->display_options['sorts']['field_cinapruhidna_amount']['expose']['label'] = 'По ціні';
/* Контекстний фільтр: Вміст: Містить ID терміна таксономії (з глибиною) */
$handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
$handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
$handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
$handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Все';
$handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
$handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
$handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
$handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
  'catalog' => 'catalog',
);
$handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '1';
/* Критерій фільтрування: Вміст: Опубліковано */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Критерій фільтрування: Вміст: Тип */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'predtovaru' => 'predtovaru',
);
/* Критерій фільтрування: Торгівля: Товар: Ціна для роздрібних покупців (field_cinaklientov:amount) */
$handler->display->display_options['filters']['field_cinaklientov_amount']['id'] = 'field_cinaklientov_amount';
$handler->display->display_options['filters']['field_cinaklientov_amount']['table'] = 'field_data_field_cinaklientov';
$handler->display->display_options['filters']['field_cinaklientov_amount']['field'] = 'field_cinaklientov_amount';
$handler->display->display_options['filters']['field_cinaklientov_amount']['relationship'] = 'field_sviy_tovar_product_id';
$handler->display->display_options['filters']['field_cinaklientov_amount']['operator'] = '<';
$handler->display->display_options['filters']['field_cinaklientov_amount']['value']['value'] = '5000';
$handler->display->display_options['filters']['field_cinaklientov_amount']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_cinaklientov_amount']['expose']['operator_id'] = 'field_cinaklientov_amount_op';
$handler->display->display_options['filters']['field_cinaklientov_amount']['expose']['label'] = 'По ціні';
$handler->display->display_options['filters']['field_cinaklientov_amount']['expose']['use_operator'] = TRUE;
$handler->display->display_options['filters']['field_cinaklientov_amount']['expose']['operator'] = 'field_cinaklientov_amount_op';
$handler->display->display_options['filters']['field_cinaklientov_amount']['expose']['identifier'] = 'field_cinaklientov_amount';
$handler->display->display_options['filters']['field_cinaklientov_amount']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  5 => 0,
  6 => 0,
);
/* Display: Сторінка */
$handler = $view->new_display('page', 'Сторінка', 'page_1');
$handler->display->display_options['path'] = 'taxonomy/term/%';
  $views[$view->name] = $view;
  return $views;
}