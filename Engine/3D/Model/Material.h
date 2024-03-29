#pragma once
#include "Utility/MathFunction.h"
#include <d3d12.h>
#include <wrl.h>

/// <summary>
/// マテリアル
/// </summary>
class Material {
private:
	//エイリアステンプレート
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	/// <summary>
	/// 定数バッファ用の構造体
	/// </summary>
	struct ConstBufferDataMaterial {
		Vector4 color;
		Matrix4x4 uvTransform;
	};

	/// <summary>
	/// マテリアルの作成
	/// </summary>
	void Initialize();

	/// <summary>
	/// マテリアルの更新
	/// </summary>
	void Update();

	/// <summary>
	/// グラフィックスコマンドのセット
	/// </summary>
	/// <param name="rootParameterIndex"></param>
	void SetGraphicsCommand(UINT rootParameterIndex);

	/// <summary>
	/// 色を取得
	/// </summary>
	/// <returns></returns>
	const Vector4& GetColor() const { return color_; };

	/// <summary>
	/// 色を設定
	/// </summary>
	/// <param name="color"></param>
	void SetColor(const Vector4& color) { color_ = color; };

	/// <summary>
	/// uv座標を取得
	/// </summary>
	/// <returns></returns>
	const Vector2& GetTranslation() const { return translation_; };

	/// <summary>
	/// uv座標を設定
	/// </summary>
	/// <param name="translation"></param>
	void SetTranslation(const Vector2& translation) { translation_ = translation; };

	/// <summary>
	/// uv角度を取得
	/// </summary>
	/// <returns></returns>
	const float& GetRotation() const { return rotation_; };

	/// <summary>
	/// uv角度を設定
	/// </summary>
	/// <param name="rotation"></param>
	void SetRotation(const float& rotation) { rotation_ = rotation; };

	/// <summary>
	/// uvスケールを取得
	/// </summary>
	/// <returns></returns>
	const Vector2& GetScale() const { return scale_; };

	/// <summary>
	/// uvスケールを設定
	/// </summary>
	/// <param name="scale"></param>
	void SetScale(const Vector2& scale) { scale_ = scale; };

private:
	//マテリアル用のリソース
	ComPtr<ID3D12Resource> materialResource_ = nullptr;
	//色
	Vector4 color_ = { 1.0f,1.0f,1.0f,1.0f };
	//uv座標
	Vector2 translation_{ 0.0f,0.0f };
	//uv角度
	float rotation_ = 0.0f;
	//uvスケール
	Vector2 scale_{ 1.0f,1.0f };

};