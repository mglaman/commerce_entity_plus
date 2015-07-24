<?php

/**
 * @file
 * @todo.
 */

class CommerceOrder extends CommerceEntity {
  /**
   * {@inheritdoc}
   */
  public function getEntityType() {
    return 'commerce_order';
  }

  public function getOrderNumber() {
    return $this->wrapperGet('order_number')->value();
  }

  public function setOrderNumber($string) {
    $this->wrapperGet('order_number')->set($string);
    return $this;
  }

  /**
   * Returns line item entities from order.
   *
   * @return EntityStructureWrapper|EntityListWrapper
   * @throws \EntityMetadataWrapperException
   */
  public function getLineItems() {
    return $this->wrapper()->get('commerce_line_items');
  }

  /**
   * Adds a line item to the order.
   *
   * @param $lineItem
   *
   * @return $this
   * @throws \CommerceException
   */
  public function addLineItem($lineItem) {
    $this->wrapper->{'commerce_line_items'}[] = $this->resolveEntity($lineItem);
    return $this;
  }
}
