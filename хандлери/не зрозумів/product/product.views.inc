<?php
/**
 * Implements hook_views_data().
 */
function product_views_data() {
  $data = array();
 
  // �������� ����� 'group' ����� ������������ � UI ��� ����������� �����,
  // ��������, ���������� � �.�.
  $data['product']['table']['group']  = t('Product');
 
  // ��������� ������� �������, �� ������� Views ����� ��������� ������.
  $data['product']['table']['base'] = array(
    'field' => 'id', // ���� ��������������.
    'title' => t('Product'),
  );
 
  // ���������, ��� ������� ������ ������ �� ��������.
  $data['product']['table']['entity type'] = 'product';
 
  // ��������� ���� "id".
  $data['product']['id'] = array(
    'title' => t('Product ID'), // ��������-�������� �������� ����, ������� ������������ � UI.
    'help' => t('The unique internal identifier of the product.'), // �������� ����, ������� ������������ � UI.
    // ���������� ��� ������ id.
    'field' => array(
      'handler' => 'product_handler_field_product', // ����������, ������� ����� �������� �������� ����.
      'click sortable' => TRUE, // ������������ ��� ���������� ��� ����������� ������ � �������.
    ),
    // ���������� ��� �������� id � �������� ���������.
    'argument' => array(
      'handler' => 'product_handler_argument_product_id', // ����������, ������� ����� ��������� ��������, � ����������� ������ �� ����.
      'name field' => 'id', // ���� ��� ����������� summary.
      'numeric' => TRUE,
      'validate type' => 'id',
    ),
    // ���������� ��� �������� id � �������� �������.
    'filter' => array(
      'handler' => 'views_handler_filter_numeric', // ����������, ������� ����� ����������� ������.
    ),
    // ���������� ��� ���������� �� id.
    'sort' => array(
      'handler' => 'views_handler_sort', // ����������, ������� ����� ����������� ������.
    ),
  );
 
  // ��������� ���� "���������".
  $data['product']['title'] = array(
    'title' => t('Title'),
    'help' => t('The product title.'),
    // ���������� ��� ������ ���������.
    'field' => array(
      'field' => 'title',
      'group' => t('Product'),
      'handler' => 'product_handler_field_product',
      'click sortable' => TRUE,
      'link_to_product_default' => TRUE,
    ),
    // ���������� ��� �������� ��������� � �������� ���������.
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    // ���������� ��� �������� ��������� � �������� �������.
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    // ���������� ��� ���������� �� ���������.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
 
  // ��������� ���� "���� ��������".
  $data['product']['created'] = array(
    'title' => t('Post date'),
    'help' => t('The date the product was created.'),
    // ���������� ��� ������ ���� ��������.
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    // ���������� ��� �������� ���� �������� � �������� �������.
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    // ���������� ��� ���������� �� ���� ��������.
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
 
  // ��������� ���� "���� ����������".
  $data['product']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the product was last updated.'),
    // ���������� ��� ������ ���� ����������.
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    // ���������� ��� �������� ���� ���������� � �������� �������.
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    // ���������� ��� ���������� �� ���� ����������.
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
 
  // ��������� ���� "������".
  $data['product']['status'] = array(
    'title' => t('Product status'),
    'help' => t('The workflow status of the product.'),
    // ���������� ��� ������ �������.
    'field' => array(
      'handler' => 'product_handler_field_product_status',
      'click sortable' => TRUE,
    ),
    // ���������� ��� �������� ������� � �������� �������.
    'filter' => array(
      'handler' => 'product_handler_filter_product_status',
    ),
    // ���������� ��� ���������� �� �������.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
 
  // ��������� ���� "uid".
  $data['product']['uid'] = array(
    'title' => t('User uid'),
    'help' => t('The user author. If you need more fields than the uid add the content: author relationship'),
    // ���������� ��� ����� ������� "product" � �������� "users".
    'relationship' => array(
      'title' => t('Author'), // ��������-�������� �������� �����, ������� ������������ � UI.
      'help' => t('Relate product to the user who created it.'), // �������� �����, ������� ������������ � UI.
      'handler' => 'views_handler_relationship',
      'base' => 'users', // �������� �������, ������� ����� ������������, � ������ ������� ��� ������� "users".
      'field' => 'uid', // �� ������ ���� ������� ����� �������.
      'label' => t('author'), // �������� ����� �����, ������� ������������ � UI.
    ),
    // ���������� ��� ������ uid.
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
    // ���������� ��� �������� uid � �������� ���������.
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    // ���������� ��� �������� uid � �������� �������.
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
  );
 
  // ��������� ���� � ����������� ���������� ��� ���������.
  $data['product']['operations'] = array(
    // ���������� ��� ��������.
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the product.'),
      'handler' => 'product_handler_field_product_operations',
    ),
  );
 
  return $data;
}