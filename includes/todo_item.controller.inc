<?php

/**
 * @file
 * Provides a controller building upon EntityAPIController
 */

/**
 * Controller for todo_items
 */
class TodoItemAPIController extends EntityAPIController {
  
  /**
   * Overrides to update relevant TodoList
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $return = parent::save($entity, $transaction);
    // Update number of active items in list
    $list_entity = entity_load_single('todo_list', $entity->lid);
    $result = db_query('SELECT lid, status  FROM {todo_item} WHERE lid=:lid AND status > 0', array(':lid' => $list_entity->lid));
    $list_entity->items = $result->rowCount();
    $list_entity->save();
    return $return;
  }

}
