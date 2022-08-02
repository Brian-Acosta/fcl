//
// Created by brian on 8/1/22.
//

#ifndef FCL_SHAPE_HEIGHT_FIELD_H
#define FCL_SHAPE_HEIGHT_FIELD_H

#include <iostream>

#include "fcl/geometry/shape/shape_base.h"

namespace fcl
{

/// @brief height field centered at the origin
template <typename S_>
class FCL_EXPORT HeightField : public ShapeBase<S_>
{
public:

  using S = S_;

  HeightField(MatrixX<S> heights, S dim_x, S dim_y, S depth);

  int nx;
  int ny;
  S dim_x;
  S dim_y;
  S depth;
  S x_resolution;
  S y_resolution;
  MatrixX<S> heights;
  VectorX<S> x_grid;
  VectorX<S> y_grid;
  void computeLocalAABB() override;
  auto getNodeType() const -> NODE_TYPE override;
  auto computeMomentofInertia() const -> Matrix3<S> override;
  auto computeVolume() const -> S override;

};

using HeightFieldf = HeightField<float>;
using HeightFieldd = HeightField<double>;

} //namespace fcl

#include "fcl/geometry/shape/height_field-inl.h"

#endif
