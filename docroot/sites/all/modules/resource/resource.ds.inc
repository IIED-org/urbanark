<?php
/**
 * @file
 * resource.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function resource_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|resource|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|featured';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'featured';
  $ds_fieldsetting->settings = array(
    'cover_large' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'conditions' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more >',
        'wrapper' => '',
        'class' => '',
        'conditions' => array(),
      ),
    ),
  );
  $export['node|resource|featured'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'download_button' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'sidebar_image' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'video_embed' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:9:{s:5:"label";s:6:"hidden";s:9:"formatter";s:27:"video_embed_field_thumbnail";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:2:{s:11:"image_style";s:9:"cover_med";s:10:"image_link";s:7:"content";}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:21:"node:field_videoembed";}',
        'load_terms' => 0,
        'conditions' => array(
          0 => array(
            'condition' => 'hide_if_string',
            'configuration' => array(
              'target' => 'sidebar_image',
              'string' => '',
            ),
          ),
        ),
      ),
    ),
    'links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|resource|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'thumbnail' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'conditions' => array(),
      ),
    ),
  );
  $export['node|resource|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'thumbnail' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'conditions' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more >',
        'wrapper' => '',
        'class' => '',
        'conditions' => array(),
      ),
    ),
  );
  $export['node|resource|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function resource_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_cover_image',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_cover_image' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|resource|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|featured';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'featured';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'cover_large',
        1 => 'field_videoembed',
        2 => 'title',
        3 => 'body',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'cover_large' => 'ds_content',
      'field_videoembed' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|resource|featured'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_videoembed',
        1 => 'body',
        2 => 'links',
        3 => 'comments',
      ),
      'sidebar' => array(
        4 => 'sidebar_image',
        5 => 'video_embed',
        6 => 'download_button',
        7 => 'field_date',
        8 => 'field_author_s_',
        9 => 'field_material_type',
        10 => 'field_no_of_pages',
        11 => 'field_isbn',
        12 => 'field_doi',
        13 => 'field_theme',
        14 => 'field_tags',
        15 => 'field_file',
      ),
    ),
    'fields' => array(
      'field_videoembed' => 'ds_content',
      'body' => 'ds_content',
      'links' => 'ds_content',
      'comments' => 'ds_content',
      'sidebar_image' => 'sidebar',
      'video_embed' => 'sidebar',
      'download_button' => 'sidebar',
      'field_date' => 'sidebar',
      'field_author_s_' => 'sidebar',
      'field_material_type' => 'sidebar',
      'field_no_of_pages' => 'sidebar',
      'field_isbn' => 'sidebar',
      'field_doi' => 'sidebar',
      'field_theme' => 'sidebar',
      'field_tags' => 'sidebar',
      'field_file' => 'sidebar',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|resource|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'thumbnail',
        1 => 'field_videoembed',
        2 => 'title',
        3 => 'body',
        4 => 'field_material_type',
        5 => 'field_no_of_pages',
        6 => 'field_author_s_',
        7 => 'field_date',
      ),
    ),
    'fields' => array(
      'thumbnail' => 'ds_content',
      'field_videoembed' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_material_type' => 'ds_content',
      'field_no_of_pages' => 'ds_content',
      'field_author_s_' => 'ds_content',
      'field_date' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|resource|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'thumbnail',
        1 => 'field_videoembed',
        2 => 'title',
        3 => 'body',
        4 => 'field_material_type',
        5 => 'field_no_of_pages',
        6 => 'field_author_s_',
        7 => 'node_link',
      ),
    ),
    'fields' => array(
      'thumbnail' => 'ds_content',
      'field_videoembed' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_material_type' => 'ds_content',
      'field_no_of_pages' => 'ds_content',
      'field_author_s_' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|resource|teaser'] = $ds_layout;

  return $export;
}
