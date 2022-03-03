/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ACCESSIBILITY_UI_TEST_ABILITY_LISTENER_H
#define ACCESSIBILITY_UI_TEST_ABILITY_LISTENER_H

#include "key_event.h"
#include "accessibility_event_info.h"

namespace OHOS {
namespace Accessibility {
class IAccessibleUITestAbilityListener {
public:
  virtual void OnAbilityConnected() = 0;
  /**
   * @brief Called when an accessibility event occurs.
   * @param eventInfo The infomation of accessible event.
   * @return
   */
  virtual void OnAccessibilityEvent(const AccessibilityEventInfo &eventInfo) = 0;

  /**
   * @brief Called when a key event occurs.
   * @param keyEvent Indicates the key event to send.
   * @param sequence The sequence of the key event.
   * @return
   */
  virtual bool OnKeyPressEvent(const MMI::KeyEvent &keyEvent, const int sequence) = 0;

  /**
   * @brief Called when need to notify the result of simulation gesture.
   * @param sequence The sequence of gesture.
   * @param completedSuccessfully The result of gesture completion.
   * @return
   */
  virtual void OnGestureSimulateResult(const int sequence, const bool completedSuccessfully) = 0;
};
} // namespace Accessibility
} // namespace OHOS
#endif  // ACCESSIBILITY_UI_TEST_ABILITY_LISTENER_H