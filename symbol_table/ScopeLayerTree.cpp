#include "ScopeLayerTree.h"

ScopeLayerTree::ScopeLayerTree(std::shared_ptr<ScopeLayer> root) : root_(std::move(root)) {}