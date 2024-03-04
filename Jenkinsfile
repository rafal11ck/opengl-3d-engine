pipeline {
    agent {
        docker {
            image 'archlinux'
            args '-v /var/jenkins_home/workspace/opengl-3d-engine_main/build:/var/jenkins_home/workspace/opengl-3d-engine_main/build'
        }
    }
    stages{
        stage('Install dempendencies'){
            steps{
                sh 'pacman -Sy --noconfirm cmake base-devel doxygen graphviz git glew sfml glm'
            }
        }
        stage('Configure CMake project'){
            steps{
                sh 'cmake -B build/'
            }
        }
        stage('Compile'){
            steps{
                sh 'cmake --build build/ -j'
            }
        }
    }
}
