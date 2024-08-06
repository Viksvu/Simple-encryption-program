#include "olcGameEngine.h"


struct vec3{
	float x, y, z;
	
	};
	
struct triangle{
	vec3 v[3];
	
	
	};
	
struct mesh{
	std::vector<triangle> msh;
	
	};
	
	
struct mat4x4{
	float m[4][4] = {0};
	
	};

	
	
		
class Engine3D : public olcConsoleGameEngine{
	public:
	Engine3D(){
		m_sAppName = L"3D construc";
		
		}
		
	private:
	mesh meshcube;
	mat4x4 matProj;
	
	
	void DaugybaMatricosVectoriu(vec3 &i, vec3 &o, mat4x4 &m){
		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
		
		float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

		if(w != 0.0f){
			o.x /= w; o.y /= w; o.z /= w;
		}
		
		
	}
		
	void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, short c=0x2588, short col=0x000F) override{
		DrawLine();
		
		
		}
	
		
	public:
	bool OnUserCreate() override{
		meshCube.msh = {
	// GALAS		
	mesh.push_back({ { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 0.0f } });
    mesh.push_back({ { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } });

    // DESNE
    mesh.push_back({ { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } });
    mesh.push_back({ { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f, 1.0f } });

    // PRIEKIS
    mesh.push_back({ { 1.0f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 1.0f } });
    mesh.push_back({ { 1.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } });

    // KAIRE
    mesh.push_back({ { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } });
    mesh.push_back({ { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } });

    // VIRSUS
    mesh.push_back({ { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 1.0f } });
    mesh.push_back({ { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f, 0.0f } });

    // APACIA
    mesh.push_back({ { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f } });
    mesh.push_back({ { 1.0f, 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } });


			
			};
	//PROJEKCIJA
	float fArti=0.1f;
	float fToli=1000.0f;
	float fFov=90.0f;
	float fApratio = (float)ScreenHeight()/(float)ScreenWidth();
	float fFovRad = 1.0f / tanf(fFov/180.0f * 2f * 3.14159f);
	
	matProj.m[0][0]=fApratio*fFovRad;
	matProj.m[1][1]=fFovRad;
	matProj.m[2][2]=fArti/(fToli-fArti);
	matProj.m[3][2]=(-fToli*fArti)/(fToli - fArti);
	matProj.m[2][3]=1.0f;
	
		
		
		return true;
		}
	bool OnUserUpdate(float FETime) override{
		
		mat4x4 matRotZ, matRotX;
		
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);
		
		
		fNormTime += 1.0f * FETime;
		matRotZ.m[0][0] = cosf(fNormTime);
		matRotZ.m[0][1] = sinf(fNormTime);
		matRotZ.m[1][0] = -sinf(fNormTime);
		matRotZ.m[1][1] = cosf(fNormTime);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;

		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fNormTime * 0.5f);
		matRotX.m[1][2] = sinf(fNormTime * 0.5f);
		matRotX.m[2][1] = -sinf(fNormTime * 0.5f);
		matRotX.m[2][2] = cosf(fNormTime * 0.5f);
		matRotX.m[3][3] = 1;
		
		
		for(auto tri : meshCube.msh){
			
			triangle triProj, triTrans, triRotaZ, triRotaX, triRotaZX;
			
			for(int i=0;i<3;i++){
				DaugybaMatricosVectoriu(tri.v[i], triRotaZ.v[i], matRotZ);		
				}
		
	        for(int i=0;i<3;i++){
				DaugybaMatricosVectoriu(triRotaZ.v[i], triRotaZX.v[i], matRotX);		
				}
				
			
			triTrans = triRotaZX;
			for(int i=0;i<3;i++){
				triTrans.p[i].z = triRotaZX.p[i].z + 3.0f;
				
				}
			
			for(int i=0;i<3;i++){
			DaugybaMatricosVectoriu(tri.v[i], triProj.v[i], matProj);
		    }
		    triProj.p[0].x += 1.0f; triProj.p[0].y += 1.0f;
			triProj.p[1].x += 1.0f; triProj.p[1].y += 1.0f;
			triProj.p[2].x += 1.0f; triProj.p[2].y += 1.0f;
			
			
			triProj.p[0].x *= 0.5f * (float)ScreenWidth();
			triProj.p[0].y *= 0.5f * (float)ScreenHeight();
			triProj.p[1].x *= 0.5f * (float)ScreenWidth();
			triProj.p[1].y *= 0.5f * (float)ScreenHeight();
			triProj.p[2].x *= 0.5f * (float)ScreenWidth();
			triProj.p[2].y *= 0.5f * (float)ScreenHeight();
			
			
		    DrawTriangle(triProj.v[0].x, triProj.v[0].y,
		    triProj.v[1].x, triProj.v[1].y,
		    triProj.v[2].x, triProj.v[2].y,
		    PIXEL_SOLID, FG_WHITE);
		    
		    
		    )
		    
		    
		    
			}
		
		
		return true;
		}
	}
	
	





int main(){
	
	Engine3D cnstr;
	
	if(cnstr.ConstructConsole(256, 240, 4, 4))
		cnstr.Start();
	else std::cout<<"ERROR console construction\n";
	
	return 0;
	
	}
