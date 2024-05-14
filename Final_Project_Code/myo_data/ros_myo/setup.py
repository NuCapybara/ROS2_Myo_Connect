from setuptools import find_packages, setup

package_name = 'ros_myo'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', 
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml', 
                                   'launch/turtle_analog.launch.xml', 
                                   'launch/turtle_pose.launch.xml',
                                   ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jialuyu',
    maintainer_email='jialuyu2024@u.northwestern.edu',
    description='Myo band data',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'turtleSimDrive = ros_myo.TurtlesimDrive:main',
            'myoDemo = ros_myo.MyoDemo:main',
            'connectMyo = ros_myo.ConnectMyo:main'
        ],
    },
)