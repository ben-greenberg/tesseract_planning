/**
 * @file instructions_trajectory.h
 * @brief Trajectory Container implementation for command language instructions
 *
 * @author Levi Armstrong
 * @date March 3, 2021
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2021, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TESSERACT_TIME_PARAMETERIZATION_INSTRUCTIONS_TRAJECTORY_H
#define TESSERACT_TIME_PARAMETERIZATION_INSTRUCTIONS_TRAJECTORY_H

#include <tesseract_common/macros.h>
TESSERACT_COMMON_IGNORE_WARNINGS_PUSH
#include <vector>
TESSERACT_COMMON_IGNORE_WARNINGS_POP

#include <tesseract_time_parameterization/trajectory_container.h>
#include <tesseract_command_language/core/instruction.h>
#include <tesseract_command_language/composite_instruction.h>

namespace tesseract_planning
{
class InstructionsTrajectory : public TrajectoryContainer
{
public:
  InstructionsTrajectory(std::vector<std::reference_wrapper<Instruction>> trajectory);
  InstructionsTrajectory(CompositeInstruction& program);

  const Eigen::VectorXd& getPosition(Eigen::Index i) const;
  const Eigen::VectorXd& getVelocity(Eigen::Index i) const;
  const Eigen::VectorXd& getAcceleration(Eigen::Index i) const;

  void setData(Eigen::Index i, const Eigen::VectorXd& velocity, const Eigen::VectorXd& acceleration, double time);

  Eigen::Index size() const;
  Eigen::Index dof() const;
  bool empty() const;

private:
  std::vector<std::reference_wrapper<Instruction>> trajectory_;
  Eigen::Index dof_;
};
}  // namespace tesseract_planning
#endif  // TESSERACT_TIME_PARAMETERIZATION_INSTRUCTIONS_TRAJECTORY_H
