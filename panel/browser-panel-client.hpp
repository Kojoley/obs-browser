#pragma once

#include "cef-headers.hpp"
#include "browser-panel-internal.hpp"

class QCefBrowserClient : public CefClient,
                          public CefDisplayHandler,
                          public CefRequestHandler,
                          public CefLifeSpanHandler,
                          public CefLoadHandler {

public:
	inline QCefBrowserClient(QCefWidgetInternal *widget_)
		: widget(widget_)
	{
	}

	/* CefClient */
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override;
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override;
	virtual CefRefPtr<CefRequestHandler> GetRequestHandler() override;
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;

	/* CefDisplayHandler */
	virtual void OnTitleChange(
			CefRefPtr<CefBrowser> browser,
			const CefString &title) override;

	/* CefRequestHandler */
	virtual bool OnBeforeBrowse(
			CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			CefRefPtr<CefRequest> request,
			bool user_gesture,
			bool is_redirect) override;

	/* CefLifeSpanHandler */
	virtual bool OnBeforePopup(
			CefRefPtr<CefBrowser> browser,
			CefRefPtr<CefFrame> frame,
			const CefString &target_url,
			const CefString &target_frame_name,
			CefLifeSpanHandler::WindowOpenDisposition target_disposition,
			bool user_gesture,
			const CefPopupFeatures &popupFeatures,
			CefWindowInfo &windowInfo,
			CefRefPtr<CefClient> &client,
			CefBrowserSettings &settings,
			bool *no_javascript_access) override;

	QCefWidgetInternal *widget = nullptr;

	IMPLEMENT_REFCOUNTING(QCefBrowserClient);
};
