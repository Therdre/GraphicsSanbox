#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <d3dcompiler.h>


#include "Camera.h"
#include "Renderer.h"
#include "Lighting.h"
#include "Material.h"

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "d3dcompiler.lib")


struct VERTEX
{
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT3 color;
};


struct VS_CONSTANT_BUFFER
{
	DirectX::XMFLOAT4X4 world;
	DirectX::XMFLOAT4X4 worldInvTraspose;
	DirectX::XMFLOAT4X4 worldViewProjection;
};

struct PS_cbPerFrame
{
	DirectX::XMFLOAT3 gEyePosW;
	float pad;
	Material mat;
	DirectionalLight gDirLight;	
};

class Graphics
{
	public:
		
		~Graphics();

		static Graphics& GetInstance();
		void Initialize(HWND hWnd, int width, int height);
		void Update(float dt);
		void Close();
	private:
		Graphics();

		//directx stuff
		IDXGISwapChain *swapchain;             // the pointer to the swap chain interface
		ID3D11Device *dev;                     // the pointer to our Direct3D device interface
		ID3D11DeviceContext *devcon;           // the pointer to our Direct3D device context
		ID3D11RenderTargetView *backbuffer;    // back buffer
		ID3D11VertexShader *pVS;    // the vertex shader
		ID3D11PixelShader *pPS;     // the pixel shader
		ID3D11Buffer *pVBuffer;    // vertex buffer
		ID3D11Buffer*   indicesBuffer; //constant buffer
		ID3D11Buffer*   pConstantBuffer11; //constant buffer
		ID3D11Buffer*   pConstantBufferPS; //constant buffer
		ID3D11Buffer*   pConstantBufferPSMat; //constant buffer
		ID3D11InputLayout *pLayout;    // global
		ID3D11DepthStencilView* mDepthStencilView;
		ID3D11RasterizerState * g_pRasterState;

		void CreateViewPort(int width, int height);

		void CreateShaders();

		void CreateBuffer();


		//our engine stuff
		Camera camera;
		MeshData sphere;
};

#endif