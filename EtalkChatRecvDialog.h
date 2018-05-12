#pragma oce

#ifndef __ETALKCHATRECVDIALOG__H_
#define __ETALKCHATRECVDIALOG__H_

#include "EtalkLive.h"
#include "EtalkImageViewer.h"

class EtalkChatRecvDialog
{
public:
	EtalkChatRecvDialog(struct EtalkChildDialogParameter *pEtalkChildDialogParameter);
	~EtalkChatRecvDialog();
	void SetParent(void *pParent);
	void SetLanguageType(LanguageType eLanguageType);
	CControlUI *GetHWND();
	void Show(bool IsShow = true);
	CControlUI *CreateChatRecvDialog();
	void InitControl();
	void CustomNotify(TNotifyUI& msg);
	void CustomHandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	struct EtalkChildDialogParameter *GetEtalkChildDialogParameter();

	void FillLocalMsgContent(char *Name, uint32_t UUID, char *Content, uint32_t Len);
	void FillRemoteMsgContent(char *Name, uint32_t UUID, char *Content, uint32_t Len);
	void FillLocalPicture(char *Name, uint32_t UUID, char *PicturePath);
	void FillRemotePicture(char *Name, uint32_t UUID, char *PicturePath);

private:
	CListContainerElementUI *CreateSendBubblesItem();
	CListContainerElementUI *CreateRecvBubblesItem();
	bool InsertImageToRichEdit(CRichEditUI *pRicEdit, const WCHAR *pImagePath, RECT &PaintRect, IOleClientSite *&pOleClientSite);
	bool InsertImageToRichEdit(CRichEditUI *pRichEdit, HBITMAP *pBitmap, RECT &PaintRect, IOleClientSite *&pOleClientSite);
public:
	CLabelUI *m_pTitle;
	CListUI *m_pRecvChatMessage;
	EtalkImageViewerDialog *m_pEtalkImageViewerDialog;
private:
	CControlUI *m_pHWND;
	struct EtalkChildDialogParameter m_EtalkChildDialogParameter;
};

#endif