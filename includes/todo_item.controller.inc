<?php

/**
 * @file
 * Provides a controller building upon EntityAPIController
 */

/**
 * Controller for todo_item
 */
class TodoItemController extends EntityAPIController {
  
  /**
   * Overrides to update relevant TodoList
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $return = parent::save($entity, $transaction);
    // Update list so number of items stays current
    $list_entity = entity_load_single('todo_list', $entity->lid);
    $list_entity->save();
    return $return;
  }

}
