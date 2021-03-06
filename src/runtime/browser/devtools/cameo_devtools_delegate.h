// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CAMEO_SRC_RUNTIME_BROWSER_DEVTOOLS_CAMEO_DEVTOOLS_DELEGATE_H_
#define CAMEO_SRC_RUNTIME_BROWSER_DEVTOOLS_CAMEO_DEVTOOLS_DELEGATE_H_

#include <string>
#include <vector>

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "content/public/browser/devtools_http_handler_delegate.h"

namespace content {
class DevToolsHttpHandler;
}

namespace cameo {

class RuntimeContext;

class CameoDevToolsDelegate : public content::DevToolsHttpHandlerDelegate {
 public:
  explicit CameoDevToolsDelegate(RuntimeContext* runtime_context);
  virtual ~CameoDevToolsDelegate();

 private:
  // DevToolsHttpProtocolHandler::Delegate overrides.
  virtual std::string GetDiscoveryPageHTML() OVERRIDE;
  virtual bool BundlesFrontendResources() OVERRIDE;
  virtual base::FilePath GetDebugFrontendDir() OVERRIDE;
  virtual std::string GetPageThumbnailData(const GURL& url) OVERRIDE;
  virtual content::RenderViewHost* CreateNewTarget() OVERRIDE;
  virtual TargetType GetTargetType(content::RenderViewHost*) OVERRIDE;
  virtual std::string GetViewDescription(content::RenderViewHost*) OVERRIDE;
  virtual scoped_refptr<net::StreamListenSocket> CreateSocketForTethering(
      net::StreamListenSocket::Delegate* delegate,
      std::string* name);

  RuntimeContext* runtime_context_;

  DISALLOW_COPY_AND_ASSIGN(CameoDevToolsDelegate);
};

}  // namespace cameo

#endif  // CAMEO_SRC_RUNTIME_BROWSER_DEVTOOLS_CAMEO_DEVTOOLS_DELEGATE_H_
