/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2016 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/

#ifndef IVW_CEFINTERACTIONHANDLER_H
#define IVW_CEFINTERACTIONHANDLER_H

#include <modules/webbrowser/webbrowsermoduledefine.h>
#include <inviwo/core/interaction/events/mouseevent.h>

#include <include/cef_browser.h>

namespace inviwo {

/*\class CEFInteractionHandler
 * Translates Inviwo events to CEF events and injects them into provided CefBrowserHost.
 */
class IVW_MODULE_WEBBROWSER_API CEFInteractionHandler : public InteractionHandler {
public:
    /*
     * @param host The browser to inject events into.
     */
    CEFInteractionHandler(CefRefPtr<CefBrowserHost> host);
    virtual ~CEFInteractionHandler() = default;

    virtual std::string getClassIdentifier() const { return "org.inviwo.cefinteractionhandler"; }

    void invokeEvent(Event* event) override;

private:
    CefKeyEvent mapKeyEvent(KeyboardEvent* e);
    CefMouseEvent mapMouseEvent(MouseInteractionEvent* e);

    void updateMouseStates(MouseEvent* e);
    uint32 modifiers_ = 0;
    CefRefPtr<CefBrowserHost> host_;
};

};  // namespace inviwo

#endif  // IVW_CEFINTERACTIONHANDLER_H
