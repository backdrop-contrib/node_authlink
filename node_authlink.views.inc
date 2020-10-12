<?php

/**
 * @file
 * Provide views data and handlers for authlink.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_data().
 */
function node_authlink_views_data() {

  // Table properties
  $data['node_authlink_nodes']['table']['group'] = t('Node Auth link');

  $data['node_authlink_nodes']['table']['base'] = array(
    'field' => 'nid', // This is the identifier field for the view.
    'title' => t('Node auth link nodes table'),
    'help' => t('Table for store authorization keys.'),
    'weight' => -10,
  );

  $data['node_authlink_nodes']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  // Table fields
  $data['node_authlink_nodes']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The node ID.'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('node'),
      'title' => t('Node'),
      'help' => t('Relate content to the node.'),
    ),
  );

  $data['node_authlink_nodes']['authkey'] = array(
    'title' => t('Authkey'),
    'help' => t('Authkey field.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['node_authlink_nodes']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the authkey was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Node integration
  $data['node']['node_authlink_nodes'] = array(
    'title' => t('Nid'),
    'help' => t('The node ID.'),
    'relationship' => array(
      'base' => 'node_authlink_nodes',
      'base field' => 'nid',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('node authlink'),
      'title' => t('Node Authlink'),
      'help' => t('Relate content to the node authlink table.'),
    ),
  );

  return $data;
}
