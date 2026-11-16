// PyObject *appGetImageInfo(PyObject *poSelf, PyObject *poArgs) icinde:
// Ara:
		uWidth=ilGetInteger(IL_IMAGE_WIDTH);
		uHeight=ilGetInteger(IL_IMAGE_HEIGHT);
	}

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	else
	{
		D3DXIMAGE_INFO kInfo;
		if (SUCCEEDED(D3DXGetImageInfoFromFileA(szFileName, &kInfo)))
		{
			canLoad=TRUE;
			uWidth=kInfo.Width;
			uHeight=kInfo.Height;
		}
	}
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_WHISPER_MESSENGER", 0);

// Altina ekle:
#ifdef ENABLE_GUILD_APPLICATION
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_APPLICATION", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_APPLICATION", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_MESSENGER_DETAILS", 0);

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_MARK_PNG", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_MARK_PNG", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_MARK_PNG", 0);

// Altina ekle:
#ifdef ENABLE_GUILD_GRADE_RENEWAL
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_GRADE_RENEWAL", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_GRADE_RENEWAL", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_GRADE_RENEWAL", 0);

// Altina ekle:
#ifdef ENABLE_GUILD_WINDOW_RENEWAL
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_WINDOW_RENEWAL", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GUILD_WINDOW_RENEWAL", 0);
#endif

