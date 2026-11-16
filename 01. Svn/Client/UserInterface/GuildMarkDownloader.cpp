// bool CGuildMarkDownloader::__LoginState_RecvMarkBlock() icinde:
// Bul:
				pkGrpImg->Reload();

// Degistir:
#ifdef ENABLE_GUILD_MARK_PNG
				FILE* fp = fopen(imagePath.c_str(), "rb");
				if (fp)
				{
					fseek(fp, 0, SEEK_END);
					std::vector<BYTE> vecFile(ftell(fp));
					fseek(fp, 0, SEEK_SET);
					const size_t uRead = fread(vecFile.data(), 1, vecFile.size(), fp);
					fclose(fp);
					pkGrpImg->Clear();
					pkGrpImg->Load(int(uRead), vecFile.data());
				}
				else
					pkGrpImg->Reload();
#else
				pkGrpImg->Reload();
#endif

