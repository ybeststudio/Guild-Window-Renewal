// Ara:
	BuildAllBlocks();
	return true;
}

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
static void FlipRows(void * data, UINT width, UINT height)
{
	const UINT pitch = width * sizeof(DWORD);
	std::vector<BYTE> row(pitch);
	BYTE * pb = (BYTE *) data;

	for (UINT top = 0, bottom = height - 1; top < bottom; ++top, --bottom)
	{
		memcpy(row.data(), pb + top * pitch, pitch);
		memcpy(pb + top * pitch, pb + bottom * pitch, pitch);
		memcpy(pb + bottom * pitch, row.data(), pitch);
	}
}
#endif


// void CGuildMarkImage::PutData(UINT x, UINT y, UINT width, UINT height, void * data) icinde:
// Ara:
void CGuildMarkImage::PutData(UINT x, UINT y, UINT width, UINT height, void * data)
{
	ilBindImage(m_uImg);

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	{
		std::vector<BYTE> flipped((BYTE *) data, (BYTE *) data + width * height * sizeof(DWORD));
		FlipRows(flipped.data(), width, height);
		ilSetPixels(x, HEIGHT - y - height, 0, width, height, 1, IL_BGRA, IL_UNSIGNED_BYTE, flipped.data());
		return;
	}
#endif


// void CGuildMarkImage::GetData(UINT x, UINT y, UINT width, UINT height, void * data) icinde:
// Ara:
void CGuildMarkImage::GetData(UINT x, UINT y, UINT width, UINT height, void * data)
{
	ilBindImage(m_uImg);

// Altina ekle:
#ifdef ENABLE_GUILD_MARK_PNG
	{
		ilCopyPixels(x, HEIGHT - y - height, 0, width, height, 1, IL_BGRA, IL_UNSIGNED_BYTE, data);
		FlipRows(data, width, height);
		return;
	}
#endif

