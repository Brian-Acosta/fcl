#ifndef FCL_HEIGHT_FIELD_INL_H
#define FCL_HEIGHT_FIELD_INL_H

#include "fcl/geometry/shape/height_field.h"

namespace fcl
{

extern template
class FCL_EXPORT HeightField<double>;

template <typename S>
HeightField<S>::HeightField(MatrixX<S> heights, S dim_x, S dim_y, S depth)
  : ShapeBase<S>(), heights(heights),
      x_grid(VectorX<S>::LinSpaced(heights.rows(), -dim_x / 2, dim_x / 2)),
      y_grid(VectorX<S>::LinSpaced(heights.cols(), -dim_y / 2, dim_y / 2)),
      dim_x(dim_x), dim_y(dim_y),
      depth(depth),
      x_resolution(dim_x / (heights.rows() - 1)),
      y_resolution(dim_y / (heights.cols() - 1)),
      nx(heights.cols()),
      ny(heights.rows())
{
  // Do nothing
}

template <typename S>
void HeightField<S>::computeLocalAABB()
{
  this->aabb_local.max_ = Vector3<S>(dim_x / 2, dim_y / 2, heights.maxCoeff());
  this->aabb_local.min_ = Vector3<S>(-dim_x / 2, -dim_y / 2,
                                     heights.minCoeff() - depth);
  this->aabb_center = this->aabb_local.center();
  this->aabb_radius = this->aabb_local.max_.norm();
}

template <typename S>
NODE_TYPE HeightField<S>::getNodeType() const
{
  return GEOM_HEIGHT_FIELD;
}

template <typename S>
auto HeightField<S>::computeVolume() const -> S { return 0; }

template <typename S>
auto HeightField<S>::computeMomentofInertia() const -> Matrix3<S>
{
  return Matrix3<S>::Zero();
}
} // namespace fcl


#endif