// Dosyanin uygun bir yerine ekle:
#ifdef ENABLE_GUILD_MARK_PNG
#include <wincodec.h>
#include <wrl/client.h>
#pragma comment(lib, "windowscodecs.lib")
using Microsoft::WRL::ComPtr;
#endif


// CGuildMarkUploader::CGuildMarkUploader() icinde:
// Ara:
CGuildMarkUploader::CGuildMarkUploader()
 : m_pbySymbolBuf(nullptr)

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
 , m_isMarkSent(false)
#endif


// Ara:
{
	return true;
}

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
bool CGuildMarkUploader::__LoadPng(const char *c_szFileName, UINT* peError)
{
	*peError=ERROR_LOAD;

	WCHAR wszFileName[MAX_PATH];
	if (!MultiByteToWideChar(CP_ACP, 0, c_szFileName, -1, wszFileName, MAX_PATH))
		return false;

	ComPtr<IWICImagingFactory> pkFactory;
	HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pkFactory));
	if (CO_E_NOTINITIALIZED == hr)
	{
		CoInitialize(NULL);
		hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pkFactory));
	}
	if (FAILED(hr))
		return false;

	ComPtr<IWICBitmapDecoder> pkDecoder;
	ComPtr<IWICBitmapFrameDecode> pkFrame;
	UINT uWidth, uHeight;
	if (FAILED(pkFactory->CreateDecoderFromFilename(wszFileName, NULL, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &pkDecoder))
		|| FAILED(pkDecoder->GetFrame(0, &pkFrame))
		|| FAILED(pkFrame->GetSize(&uWidth, &uHeight)))
		return false;

	if (uWidth!=SGuildMark::WIDTH)
	{
		*peError=ERROR_WIDTH;
		return false;
	}

	if (uHeight!=SGuildMark::HEIGHT)
	{
		*peError=ERROR_HEIGHT;
		return false;
	}

	ComPtr<IWICFormatConverter> pkConverter;
	if (FAILED(pkFactory->CreateFormatConverter(&pkConverter))
		|| FAILED(pkConverter->Initialize(pkFrame.Get(), GUID_WICPixelFormat32bppBGRA, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeCustom))
		|| FAILED(pkConverter->CopyPixels(NULL, SGuildMark::WIDTH * 4, sizeof(m_kMark.m_apxBuf), (BYTE*)m_kMark.m_apxBuf)))
		return false;

	return true;
}
#endif


// bool CGuildMarkUploader::__Load(const char *c_szFileName, UINT* peError) icinde:
// Ara:
bool CGuildMarkUploader::__Load(const char *c_szFileName, UINT* peError)
{

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	const char* c_szExt = strrchr(c_szFileName, '.');
	if (!c_szExt || 0 != _stricmp(c_szExt, ".tga"))
		return __LoadPng(c_szFileName, peError);
#endif


// bool CGuildMarkUploader::Connect(const CNetworkAddress& c_rkNetAddr, DWORD dwHandle, DWORD dwRandomKey, DWORD dwGuildID, const char* c_szFileName, UINT* peError) icinde:
// Ara:
	__OfflineState_Set();
	SetRecvBufferSize(1024);
	SetSendBufferSize(1024);

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	m_isMarkSent = false;

	if (!__Load(c_szFileName, peError))
		return false;
#endif


// bool CGuildMarkUploader::Connect(const CNetworkAddress& c_rkNetAddr, DWORD dwHandle, DWORD dwRandomKey, DWORD dwGuildID, const char* c_szFileName, UINT* peError) icinde:
// Ara:
	m_dwHandle = dwHandle;
	m_dwRandomKey = dwRandomKey;
	m_dwGuildID = dwGuildID;

// Altina ekle:
#ifndef ENABLE_GUILD_MARK_PNG
	if (!__Load(c_szFileName, peError))
		return false;
#endif


// bool CGuildMarkUploader::__SendMarkPacket() icinde:
// Ara:
	memcpy(kPacketMarkUpload.image, m_kMark.m_apxBuf, sizeof(kPacketMarkUpload.image));
	if (!Send(sizeof(kPacketMarkUpload), &kPacketMarkUpload))
		return false;

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	CNetworkStream::__SendInternalBuffer();
	m_isMarkSent = true;
#endif

