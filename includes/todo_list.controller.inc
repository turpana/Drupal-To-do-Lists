 <?php

/**
 * @file
 * Provides a controller building upon EntityAPIController
 */

/**
 * Controller for todo_list
 */
class TodoListController extends EntityAPIController {
  
  /**
   * Overrides to update relevant TodoList
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Update number of active items in list
    $is_new = isset($entity->is_new) ? $entity->is_new : FALSE;
    if ($is_new) {
      $entity->items = 0;
    } else {
      $result = db_query('SELECT lid, status  FROM {todo_item} WHERE lid=:lid AND status > 0', array(':lid' => $entity->lid));
      $entity->items = $result->rowCount();
    }
    // then save
    $return = parent::save($entity, $transaction);
    return $return;
  }

}
