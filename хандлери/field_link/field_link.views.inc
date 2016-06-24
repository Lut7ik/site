<?php
/**
 * Implements hook_views_data_alter().
 */
function field_link_views_data_alter(&$data) {
	// Ключ node - поле буде доступне тільки при виводі контенту.
	// Ключ field_link - машинне ім'я нашого поля.

	// Назва нашого поля (human-readable).
  $data['node']['field_link']['title'] = t('Links to author');
  // Опис нашого поля.
  $data['node']['field_link']['help'] = t('Our description.');
  // Вказуємо обробник нашого поля.
  $data['node']['field_link']['field']['handler'] = 'field_link_handler';
}
