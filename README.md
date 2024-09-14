# miniRT

## 🌟 branch naming rule

- feat-기능요약 (ex : feat-parse)
- test-테스트기능요약 (ex: test-parsetest)
- fix-주요수정된버그내용 (ex: fix-segfault)
- style-주요수정내용
- docs-문서내용

## 🌟 commit rule

### Tag : Description #issue_number
ex ) Feat : Add tokenizer#2

|Tag | Description|
|-|-|
|Feat | 새로운 기능을 추가|
|Fix |	버그 수정|
|!HOTFIX |	급하게 치명적인 버그를 고쳐야하는 경우|
|Style |	코드 포맷 변경, 세미 콜론 누락, 코드 수정이 없는 경우|
|Refactor | 프로덕션 코드 리팩토링|
|Comment |	필요한 주석 추가 및 변경|
|Test	| 테스트 코드, 리펙토링 테스트 코드 추가, Production Code(실제로 사용하는 코드) 변경 없음|
|Rename |	파일 혹은 폴더명을 수정하거나 옮기는 작업만인 경우|
|Docs | 문서 수정에 대한 커밋|
|Merge | 다른 브랜치에 있는 내용을 merge 했을 경우 |

## 🌟 role

 - 재열 : 파싱, 각뿔, 텍스처, soft shadow 구현
 - 영기 : 뷰포트, 구, 평면, 원기둥, Phong Lightning 구현

 ## 과제 소개
 - miniLibX를 사용해서 3차원 Ray Tracing을 구현해라
	- Ray Tracing이란?
		: 가상의 뷰포트를 통과하는 광선을 가정하고 그 광선을 역추적하는 방식이다.
		
		쉽게 설명하자면 우리가 흔히 "이미지를 본다"라는 것은 광원에서 나온 빛이 물체에 반사되어 우리의 눈으로 들어오는 것인데,
		이를 거꾸로 추적하여 우리의 눈에서 나온 광선이 어떤 물체와 부딪치는지 파악하고 부딪친 지점에서부터 광원까지의 광선을 다시
		추적하는 방식이다.

		원래 방식은 광선이 물체에 여러번 반사가 되면 그 과정을 모두 추적하는 것이 맞으나, 한 번만 반사되는 것으로 제한하고 구현했다.

- Phong Lighting을 구현해라.
	- Phong Lightning이란?
		: 물체의 색을 결정할 때 광원의 색과 물체의 색 그리고 물체의 반사율을 더해서 최종적인 픽셀의 색을 결정하는 것이다.
		1. ambient(주변광) : 다른 물체들로부터 반사된 빛을 단순화한 값
			- (1, 1, 1) * ambient_strength[0 ~ 1]
		2. diffuse(확산광) : 모든 빛을 난반사하는 경우의 빛을 계산
			- 교점에서의 법선벡터와 광원을 향하는 벡터의 내적값으로 계산한다. 따라서 교점의 법선벡터가 광원을 향할수록 색이 나타난다.
		3. specular(반사광) : 정반사를 표현한 빛
			- 반사된 광선과 법선벡터의 내적을 통해 반사된 광선을 법선벡터 방향으로 정사영한 크기를 구하고, 반사된 광선의 반대 방향 벡터에 앞서 구한 크기를 두 배한 값을 더하면 반사광 벡터를 구할 수 있다.
			- 반사광 벡터와 반사된 광선의 방향이 일치할 때 눈으로 가장 많은 빛이 들어오게 될 것이다.

- 도형을 구현해라
	- 구 : ray의 단위벡터 *t와의 교점을 판별식을 통해 구한다.
		   원의 중심에서 윈과 광선의 교점으로 향하는 벡터는 원점에서 교점으로 향하는 벡터에서 원점에서 원의 중심으로 향하는 벡터를 뺀 것과 같다. 이 식과 원의 중심에서 교점으로 향하는 벡터의 길이는 반지름으로 고정인 식을 연립해서 벡터방정식으로 판별식을 세워서 교점을 구하면 된다.
	- 평면 : 평면 위의 모든 직선은 법선벡터와 수직이다. 따라서 평면 위의 한 점과 법선벡터를 안다면 평면의 방정식을 유도할 수 있다.
			평면의 법선벡터와 광선의 방향벡터가 수직이 아니라면 평면과는 무조건 교점이 생기게 된다. 교점의 범위를 최소치, 최대치를 지정해두고 연산의 범위를 한정하였다.
	- 원기둥 : 원기둥의 중심과 방향 벡터, 반지름과 높이를 입력값으로 받는다.
		1. 밑면 : 원기둥의 중심으로부터 방향벡터 방향으로 높이의 절반만큼 위아래 방향으로 이동한 점을 구하고 원의 중심으로 삼는다.
				 원기둥의 방향 벡터를 법선벡터로 하고, 앞서 구한 점을 지나는 평면의 방정식을 구한다.
				 광선과 앞서 구한 평면의 교점을 구하고 원의 중심으로부터 반지름 크기까지만 hit했다고 판정한다.
		2. 옆면 : 원기둥의 중심을 지나고 방향벡터를 법선벡터로 하는 평면을 구하고 광선을 평면에 정사영한다.
				 밑면을 구한 방법으로 광선이 원기둥 범위 안에 있는지 확인하고 범위 내에 있다면 교점1의 위치를 판별식을 통해 구한다.
				 구한 교점1을 지나고 원기둥의 방향벡터를 방향벡터로 갖는 직선을 구해서 광선과의 교점2을 구하면 그 교점2가 실제 교점의 위치가 된다. 교점2와 교점1의 거리를 구하고 그 거리가 원기둥의 높이의 절반보다 작다면 hit했다고 판정한다.
				 
				 정사영하는 법 : 광선 위의 서로 다른 두 점을 정하고 한 점을 지나고 방향벡터가 평면의 법선벡터인 직선을
        				      각각 두 개를 구해서 원기둥 중심의 평면과 교점을 구해 두 점을 구한다.
  					      두 점을 지나는 직선을 구하면 그게 바로 평면에 정사영 내린 직선이 된다.


